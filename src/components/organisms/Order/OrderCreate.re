open Wis;
open Models;

[@react.component]
let make = () => {
  let form = Form.useForm(~submit=AuthService.registerManager);

  let priceField = Form.useField(~form, ~initialValue="", value => Ok(value));
  let deadlineField =
    Form.useField(~form, ~initialValue="", value => Ok(value));
  let dateField = Form.useField(~form, ~initialValue="", value => Ok(value));

  let (isLoading, setIsLoading) = React.useState(() => false);

  <form
    onSubmit={ev => {
      setIsLoading(_ => true);

      let form: Order.state = {
        order: {
          branch_id: 1,
          food_id: 1,
          expires_at: deadlineField.value,
          deadline: deadlineField.value,
          discount_price: 200,
        },
      };
      Js.Promise.(
        OrderService.post(form)
        |> then_(result => {
             switch (result) {
             | Ok((_: Order.t)) => Route.navigateTo(Account(Orders(List)))
             | Error(_) => ()
             };
             resolve();
           })
        |> ignore
      );
      ReactEvent.Synthetic.preventDefault(ReactEvent.toSyntheticEvent(ev));
    }}
    className="grid grid-cols-12 gap-6 pt-4 bg-white md:bg-transparent">
    <div
      className="shadow sm:rounded-md sm:overflow-hidden col-start-5 col-end-9">
      <div className="px-4 py-5 bg-white sm:p-6">
        <div>
          <label className="block text-sm leading-5 font-medium text-gray-700">
            {React.string({j|Food|j})}
          </label>
          <FoodsDropdown className="mt-2" />
        </div>
        <div className="mt-6">
          <label className="block text-sm leading-5 font-medium text-gray-700">
            {React.string({j|Price|j})}
          </label>
          <Input
            required=true
            placeholder="Enter price of order"
            validatedValue={priceField.valueForDisplay}
            className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
            value={priceField.value}
            onChange={priceField.onChange}
          />
        </div>
        <div className="mt-6">
          <label className="block text-sm leading-5 font-medium text-gray-700">
            {React.string({j|Food expiration date|j})}
          </label>
          <Input
            required=true
            type_="date"
            placeholder="Enter order due date"
            validatedValue={dateField.valueForDisplay}
            className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
            value={dateField.value}
            onChange={dateField.onChange}
          />
        </div>
        <div className="mt-6">
          <label className="block text-sm leading-5 font-medium text-gray-700">
            {React.string({j|Deadline of the order|j})}
          </label>
          <Input
            required=true
            type_="date"
            placeholder="Enter order due date"
            validatedValue={deadlineField.valueForDisplay}
            className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
            value={deadlineField.value}
            onChange={deadlineField.onChange}
          />
        </div>
      </div>
      <div className="px-4 py-3 bg-gray-50 text-right sm:px-6">
        <span className="inline-flex rounded-md shadow-sm">
          <Button
            type_="submit"
            disabled={form.isSubmitting}
            state={isLoading ? `Loading : `Default}
            className="inline-flex justify-center py-2 px-4 border border-transparent text-sm leading-5 font-medium rounded-md text-white bg-indigo-600 hover:bg-indigo-500 focus:outline-none focus:border-indigo-700 focus:shadow-outline-indigo active:bg-indigo-700 transition duration-150 ease-in-out">
            {React.string({j|Submit|j})}
          </Button>
        </span>
      </div>
    </div>
  </form>;
};
