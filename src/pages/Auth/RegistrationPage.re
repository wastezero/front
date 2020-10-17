[@bs.module "assets/images/restaurant.png"]
external restaurantImg: string = "default";

[@react.component]
let make = () => {
  <div
    className="min-h-screen bg-gray-50 flex flex-col justify-center py-12 sm:px-6 lg:px-8">
    <div className="sm:mx-auto sm:w-full sm:max-w-md">
      <h2
        className="mt-6 text-center text-3xl leading-9 font-extrabold text-gray-900">
        {React.string({j|Registration|j})}
      </h2>
    </div>
    <div className="mt-8 grid grid-cols-12">
      <div className="col-start-4 col-span-6">
        <div
          className="grid grid-cols-2 divide-x divide-gray-400 cursor-pointer">
          <div
            className="flex flex-col bg-white hover:bg-gray-100 items-center justify-center py-8 px-4 shadow sm:px-10 rounded-l-lg">
            <img className="w-64 h-64" src=restaurantImg />
            <p className="mt-2 text-xl font-bold">
              {React.string({j|Register Your Restaurant|j})}
            </p>
          </div>
          <div
            className="flex flex-col bg-white hover:bg-gray-100 items-center justify-center py-8 px-4 shadow sm:px-10 rounded-r-lg">
            <Icons.ManagerIllustration className="w-64 h-64" />
            <p className="mt-2 text-xl font-bold">
              {React.string({j|Register As a Manager|j})}
            </p>
          </div>
        </div>
      </div>
    </div>
    <p className="mt-2 text-center text-sm leading-5 text-gray-600 max-w">
      {React.string({j|Or|j})}
      <Link
        route=Route.Login
        className="font-medium text-indigo-600 hover:text-indigo-500 focus:outline-none focus:underline transition ease-in-out duration-150">
        {React.string({j| login here|j})}
      </Link>
    </p>
    <div className="mt-6">
      <div className="relative">
        <div className="relative flex justify-center text-sm leading-5">
          <span className="px-2 text-gray-500">
            {React.string({j|© WasteZero - 2020|j})}
          </span>
        </div>
      </div>
    </div>
  </div>;
};
