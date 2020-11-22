open Belt;
type t('model) = {
  title: string,
  content: 'model => React.element,
  textAlign: [ | `left | `center | `right],
};

module Row = {
  [@react.component]
  let make = (~item, ~columns, ~hasShadow) => {
    <tr>
      {columns
       |> List.mapWithIndex(_, (index, column) => {
            <td
              key={j|row-td:$index|j}
              className={Cn.fromList([
                "px-4 py-4 whitespace-no-wrap bg-white",
                Cn.on("sticky left-0 pl-6", index == 0),
                Cn.on("shadow-r", index == 0 && hasShadow),
                switch (column.textAlign) {
                | `left => "text-left"
                | `center => "text-center"
                | `right => "text-right"
                },
              ])}>
              {column.content(item)}
            </td>
          })
       |> List.toArray
       |> React.array}
    </tr>;
  };
};

[@react.component]
let make =
    (
      ~columns: list(t('item)),
      ~grid: (
         Request.state(Atd.Grid_wrap.t('item)),
         int,
         Paginate.action => unit,
       ),
    ) => {
  let (grid, page, onPaginate) = grid;
  let (hOffset, setHOffset) = React.useState(() => 0);

  let handleScroll = (event: ReactEvent.UI.t) => {
    let target = event->ReactEvent.UI.target;
    let offset: int = target##scrollLeft;
    setHOffset(_ => offset);
  };

  <div className="flex-1 h-0 flex flex-col">
    <div
      className={Cn.fromList([
        "max-w-100 overflow-scroll relative",
        Cn.on(
          "flex-1",
          switch (grid) {
          | `Data(_) => true
          | _ => false
          },
        ),
      ])}
      onScroll=handleScroll>
      <table className="min-w-full">
        <thead>
          <tr>
            {columns
             |> List.mapWithIndex(_, (index, column) => {
                  <th
                    key={j|header-$index|j}
                    className={Cn.fromList([
                      "sticky top-0 p-0 z-10",
                      Cn.on("shadow-r z-20", index == 0 && hOffset != 0),
                      Cn.on("left-0", index == 0),
                      switch (column.textAlign) {
                      | `left => "text-left"
                      | `center => "text-center"
                      | `right => "text-right"
                      },
                    ])}>
                    <div
                      className={Cn.fromList([
                        "px-4 py-3  border-t border-b border-gray-200 bg-gray-50 text-xs leading-4 font-medium text-cool-gray-500 uppercase whitespace-no-wrap",
                        Cn.on("pl-6", index == 0),
                      ])}>
                      {React.string(column.title)}
                    </div>
                  </th>
                })
             |> List.toArray
             |> React.array}
          </tr>
        </thead>
        <tbody
          className="bg-white divide-y divide-cool-gray-200 text-sm leading-5 text-cool-gray-900">
          {switch (grid) {
           | `Data(grid) =>
             grid.data
             |> List.mapWithIndex(_, (index, item) => {
                  <Row
                    item
                    columns
                    key={j|RequestItem-$index|j}
                    hasShadow={hOffset != 0}
                  />
                })
             |> List.toArray
             |> React.array
           | _ => React.null
           }}
        </tbody>
      </table>
    </div>
    {switch (grid) {
     | `Loading => <div className="flex-1 w-full"> <LoadingSpinner /> </div>
     | `Error(_) =>
       <div className="flex-1 w-full  flex items-center justify-center">
         {React.string({j|ошибка|j})}
       </div>
     | _ => React.null
     }}
    <PaginationView page onPaginate />
  </div>;
};
