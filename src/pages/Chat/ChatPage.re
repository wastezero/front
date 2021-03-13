[@react.component]
let make = () => {
  <main className="min-w-0 flex-1 border-t border-gray-200 xl:flex">
    <aside className="block flex-shrink-0 order-first">
      <div
        className="h-full relative flex flex-col w-96 border-r border-gray-200 bg-gray-100">
        <div className="flex-shrink-0">
          <div className="h-16 bg-white px-6 flex flex-col justify-center">
            <div className="flex items-baseline space-x-3">
              <h2 className="text-ls font-medium text-gray-900">
                {React.string({j|Inbox|j})}
              </h2>
              <p className="text-sm font-medium text-gray-500">
                {React.string({j|1 messages|j})}
              </p>
            </div>
          </div>
          <div
            className="border-t border-b border-gray-200 bg-gray-50 px-6 py-2 text-sm font-medium text-gray-500">
            {React.string({j|Sorted by date|j})}
          </div>
        </div>
        <nav className="min-h-0 flex-1 overflow-y-auto">
          <ul className="border-b border-gray-200 divide-y divide-gray-200">
            <li
              className="relative bg-white py-5 px-6 hover:bg-gray-50 focus-within:ring-2 focus-within:ring-inset focus-within:ring-blue-600">
              <div className="flex justify-between space-x-3">
                <div className="min-w-0 flex-1">
                  <a href="#" className="block focus:outline-none">
                    <span className="absolute inset-0" />
                    <p className="text-sm font-medium text-gray-900 truncate">
                      {React.string({j|Saddam Assamatullayev|j})}
                    </p>
                    <p className="text-sm text-gray-500 truncate">
                      {React.string(
                         {j|У меня проблема с статусом заказа, оно не отображается в ввиде значка|j},
                       )}
                    </p>
                  </a>
                </div>
                <time
                  className="flex-shrink-0 whitespace-nowrap text-sm text-gray-500">
                  {React.string({j|1d ago |j})}
                </time>
              </div>
              <div className="mt-1">
                <p className="line-clamp-2 text-sm text-gray-600">
                  {React.string(
                     {j|Список блюд не передается как положено и у меня проблема с статусом заказа, оно не отображается в ввиде значка как я сам хочу, но все работает|j},
                   )}
                </p>
              </div>
            </li>
          </ul>
        </nav>
      </div>
    </aside>
  </main>;
};
