open Wis;
open Models;

[@react.component]
let make = () => {
  let form = Form.useForm(~submit=AuthService.registerManager);

  let restaurantField =
    Form.useField(~form, ~initialValue=None, value =>
      switch (value) {
      | Some(wallet) => Ok(Some(wallet))
      | None => Error({j|Выберите кошелек источник|j})
      }
    );
  let nameField = Form.useField(~form, ~initialValue="", value => Ok(value));
  let descriptionField =
    Form.useField(~form, ~initialValue="", value => Ok(value));
  let priceField = Form.useField(~form, ~initialValue="", value => Ok(value));
  let cuisineField =
    Form.useField(~form, ~initialValue="", value => Ok(value));
  let ingredientsField =
    Form.useField(~form, ~initialValue="", value => Ok(value));
  let imageField = Form.useField(~form, ~initialValue="", value => Ok(value));

  let (isLoading, setIsLoading) = React.useState(() => false);

  <form
    onSubmit={ev => {
      switch (restaurantField.value) {
      | Some((restaurant: Restaurant.t)) =>
        setIsLoading(_ => true);

        let form: Food.form_body = {
          food: {
            restaurant_id: restaurant.id,
            name: nameField.value,
            description: descriptionField.value,
            price: priceField.value |> int_of_string,
            cuisine: cuisineField.value,
            ingredients: ingredientsField.value,
            image: imageField.value,
          },
        };
        Js.Promise.(
          FoodService.post(form)
          |> then_(result => {
               switch (result) {
               | Ok(_) => Route.navigateTo(Account(Foods(List)))
               | Error(_) => ()
               };
               resolve();
             })
          |> ignore
        );
      | None => ()
      };
      ReactEvent.Synthetic.preventDefault(ReactEvent.toSyntheticEvent(ev));
    }}
    className="grid grid-cols-12 gap-6 pt-4 bg-white md:bg-transparent">
    <div
      className="shadow sm:rounded-md sm:overflow-hidden col-start-5 col-end-9">
      <div className="px-4 py-5 bg-white sm:p-6">
        <div>
          <label className="block text-sm leading-5 font-medium text-gray-700">
            {React.string({j|Restaurant|j})}
          </label>
          <RestaurantsDropdown
            className="mt-2"
            value={restaurantField.value}
            onChange={restaurantField.onChange}
            validatedValue={restaurantField.valueForDisplay}
          />
        </div>
        <div className="mt-6">
          <label className="block text-sm leading-5 font-medium text-gray-700">
            {React.string({j|Name|j})}
          </label>
          <Input
            required=true
            placeholder="Enter name"
            validatedValue={nameField.valueForDisplay}
            className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
            value={nameField.value}
            onChange={nameField.onChange}
          />
        </div>
        <div className="mt-6">
          <label className="block text-sm leading-5 font-medium text-gray-700">
            {React.string({j|Description|j})}
          </label>
          <Input
            required=true
            placeholder="Enter name"
            validatedValue={descriptionField.valueForDisplay}
            className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
            value={descriptionField.value}
            onChange={descriptionField.onChange}
          />
        </div>
        <div className="mt-6">
          <label className="block text-sm leading-5 font-medium text-gray-700">
            {React.string({j|Cuisine|j})}
          </label>
          <Input
            required=true
            placeholder="Enter cuisine"
            validatedValue={cuisineField.valueForDisplay}
            className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
            value={cuisineField.value}
            onChange={cuisineField.onChange}
          />
        </div>
        <div className="mt-6">
          <label className="block text-sm leading-5 font-medium text-gray-700">
            {React.string({j|Ingredients|j})}
          </label>
          <Input
            required=true
            placeholder="Enter ingredients"
            validatedValue={ingredientsField.valueForDisplay}
            className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
            value={ingredientsField.value}
            onChange={ingredientsField.onChange}
          />
        </div>
        <div className="mt-6">
          <label className="block text-sm leading-5 font-medium text-gray-700">
            {React.string({j|Image|j})}
          </label>
          <Input
            required=true
            placeholder="Enter image"
            validatedValue={imageField.valueForDisplay}
            className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
            value={imageField.value}
            onChange={imageField.onChange}
          />
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
