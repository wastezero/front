open Wis;
open Models;

[@react.component]
let make = () => {
  let (_, dispatchToasts) = Toast.ToastsContext.useToasts();
  let (_, dispatchUserCtx) = Auth.UserContext.useUser();

  let form = Form.useForm(~submit=AuthService.registerRestaurant);

  let emailField = Form.useField(~form, ~initialValue="", value => Ok(value));
  let passwordField =
    Form.useField(~form, ~initialValue="", value => Ok(value));
  let passwordConfirmationField =
    Form.useField(~form, ~initialValue="", value =>
      if (value == passwordField.value) {
        Ok(value);
      } else {
        Error("passwords are not same");
      }
    );
  let nameField = Form.useField(~form, ~initialValue="", value => Ok(value));
  let cuisineField =
    Form.useField(~form, ~initialValue="", value => Ok(value));
  let descriptionField =
    Form.useField(~form, ~initialValue="", value => Ok(value));
  let websiteField =
    Form.useField(~form, ~initialValue="", value => Ok(value));
  let contactsField =
    Form.useField(~form, ~initialValue="", value => Ok(value));
  let avatarField =
    Form.useField(~form, ~initialValue="", value => Ok(value));

  let onSubmit = ev => {
    open Js.Promise;

    if (form.validate()) {
      form.submit({
        email: emailField.value,
        password: passwordField.value,
        password_confirmation: passwordConfirmationField.value,
        name: nameField.value,
        website: websiteField.value,
        description: descriptionField.value,
        contacts: contactsField.value,
        cuisine: cuisineField.value,
        avatar: avatarField.value,
      })
      |> then_(result => {
           Js.log2("result", result);
           switch (result) {
           | Ok((response: Protocol_v1_t.registration_response)) =>
             Config.saveUserToken(Some(response.authentication_token));
             dispatchUserCtx(UserRequested);
           | Error((err: Request.error)) =>
             dispatchToasts(
               Add({
                 id: Toast.generateId(),
                 text: {j|Error trying to submit form|j},
                 kind: `warning,
                 subtext: err.message,
                 onClick: () => (),
               }),
             )
           };
           resolve(result);
         })
      |> ignore;
    } else {
      dispatchToasts(
        Add({
          id: Toast.generateId(),
          text: {j|Error when sending form|j},
          kind: `warning,
          subtext: {j|Please check the entered fields|j},
          onClick: () => (),
        }),
      );
    };
    ReactEvent.Synthetic.preventDefault(ReactEvent.toSyntheticEvent(ev));
  };

  <div
    className="min-h-screen bg-gray-50 flex flex-col justify-start py-6 sm:px-6 lg:px-8">
    <h3
      className="text-center text-2xl leading-6 font-extrabold text-gray-900">
      {React.string({j|Register as a Manager|j})}
    </h3>
    <form onSubmit className="grid grid-cols-12 gap-6 mt-4">
      <div
        className="shadow sm:rounded-md sm:overflow-hidden col-start-5 col-end-9">
        <div className="px-4 py-5 bg-white sm:p-6">
          <div>
            <label
              className="block text-sm leading-5 font-medium text-gray-700">
              {React.string({j|Name|j})}
            </label>
            <Input
              required=true
              placeholder="Enter your name"
              validatedValue={nameField.valueForDisplay}
              className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
              value={nameField.value}
              onChange={nameField.onChange}
            />
          </div>
          <div className="mt-6">
            <label
              className="block text-sm leading-5 font-medium text-gray-700">
              {React.string({j|Email|j})}
            </label>
            <Input
              required=true
              type_="email"
              placeholder="Enter email"
              validatedValue={emailField.valueForDisplay}
              className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
              value={emailField.value}
              onChange={emailField.onChange}
            />
          </div>
          <div className="mt-6">
            <label
              className="block text-sm leading-5 font-medium text-gray-700">
              {React.string({j|Password|j})}
            </label>
            <Input
              required=true
              type_="password"
              placeholder="password"
              validatedValue={passwordField.valueForDisplay}
              className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
              value={passwordField.value}
              onChange={passwordField.onChange}
            />
          </div>
          <div className="mt-6">
            <label
              className="block text-sm leading-5 font-medium text-gray-700">
              {React.string({j|Password Confirmation|j})}
            </label>
            <Input
              required=true
              type_="password"
              validatedValue={passwordConfirmationField.valueForDisplay}
              className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
              value={passwordConfirmationField.value}
              onChange={passwordConfirmationField.onChange}
            />
          </div>
          <div className="mt-6">
            <label
              className="block text-sm leading-5 font-medium text-gray-700">
              {React.string({j|Website|j})}
            </label>
            <div className="mt-1 flex rounded-md shadow-sm">
              <span
                className="inline-flex items-center px-3 rounded-l-md border border-r-0 border-gray-300 bg-gray-50 text-gray-500 text-sm">
                {React.string({j|http://|j})}
              </span>
              <Input
                placeholder="www.example.com"
                validatedValue={websiteField.valueForDisplay}
                className="form-input flex-1 block w-full rounded-none rounded-r-md transition duration-150 ease-in-out sm:text-sm sm:leading-5"
                value={websiteField.value}
                onChange={websiteField.onChange}
              />
            </div>
          </div>
          <div className="mt-6">
            <label
              className="block text-sm leading-5 font-medium text-gray-700">
              {React.string({j|Cover photo|j})}
            </label>
            <Input
              required=true
              placeholder="Enter link for profile photo"
              validatedValue={avatarField.valueForDisplay}
              className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
              value={avatarField.value}
              onChange={avatarField.onChange}
            />
          </div>
          <div className="mt-6">
            <label
              className="block text-sm leading-5 font-medium text-gray-700">
              {React.string({j|Cuisine|j})}
            </label>
            <Input
              required=true
              placeholder="Enter cuisine of restaurant"
              validatedValue={cuisineField.valueForDisplay}
              className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
              value={cuisineField.value}
              onChange={cuisineField.onChange}
            />
          </div>
          <div className="mt-6">
            <label
              className="block text-sm leading-5 font-medium text-gray-700">
              {React.string({j|Contacts|j})}
            </label>
            <Input
              placeholder="Enter contacts of restaurant"
              validatedValue={contactsField.valueForDisplay}
              className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
              value={contactsField.value}
              onChange={contactsField.onChange}
            />
          </div>
          <div className="mt-6">
            <label
              className="block text-sm leading-5 font-medium text-gray-700">
              {React.string({j|Description|j})}
            </label>
            <Input
              multiLine=true
              placeholder="Enter description of restaurant"
              validatedValue={descriptionField.valueForDisplay}
              className="mt-2 form-input block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
              value={descriptionField.value}
              onChange={descriptionField.onChange}
            />
          </div>
        </div>
        <div className="px-4 py-3 bg-gray-50 text-right sm:px-6">
          <span className="inline-flex rounded-md shadow-sm">
            <Button
              type_="submit"
              disabled={form.isSubmitting}
              state={form.isSubmitting ? `Loading : `Default}
              className="inline-flex justify-center py-2 px-4 border border-transparent text-sm leading-5 font-medium rounded-md text-white bg-indigo-600 hover:bg-indigo-500 focus:outline-none focus:border-indigo-700 focus:shadow-outline-indigo active:bg-indigo-700 transition duration-150 ease-in-out">
              {React.string({j|Submit|j})}
            </Button>
          </span>
        </div>
      </div>
    </form>
  </div>;
};
