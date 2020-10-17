[@react.component]
let make = () => {
  <div
    className="min-h-screen bg-gray-50 flex flex-col justify-start py-6 sm:px-6 lg:px-8">
    <h3 className="text-left text-2xl leading-6 font-extrabold text-gray-900">
      {React.string({j|Register as a Manager|j})}
    </h3>
    <div className="mt-4 bg-white shadow px-4 py-5 sm:rounded-lg sm:p-6">
      <div className="md:grid md:grid-cols-3 md:gap-6">
        <div className="md:col-span-1">
          <h3 className="text-lg font-medium leading-6 text-gray-900">
            {React.string({j|Profile|j})}
          </h3>
          <p className="mt-1 text-sm leading-5 text-gray-500">
            {React.string(
               {j|This information will be displayed publicly so be careful what you share.|j},
             )}
          </p>
        </div>
        <div className="mt-5 md:mt-0 md:col-span-2">
          <form action="#" method="POST">
            <div className="grid grid-cols-3 gap-6">
              <div className="col-span-3 sm:col-span-2">
                <label
                  htmlFor="company_website"
                  className="block text-sm font-medium leading-5 text-gray-700">
                  {React.string({j|Website|j})}
                </label>
                <div className="mt-1 flex rounded-md shadow-sm">
                  <span
                    className="inline-flex items-center px-3 rounded-l-md border border-r-0 border-gray-300 bg-gray-50 text-gray-500 text-sm">
                    {React.string({j|http://|j})}
                  </span>
                  <input
                    id="company_website"
                    className="form-input flex-1 block w-full rounded-none rounded-r-md transition duration-150 ease-in-out sm:text-sm sm:leading-5"
                    placeholder="www.example.com"
                  />
                </div>
              </div>
            </div>
            <div className="mt-6">
              <label
                htmlFor="about"
                className="block text-sm leading-5 font-medium text-gray-700">
                {React.string({j|About|j})}
              </label>
              <div className="rounded-md shadow-sm">
                <textarea
                  id="about"
                  rows=3
                  className="form-textarea mt-1 block w-full transition duration-150 ease-in-out sm:text-sm sm:leading-5"
                  placeholder="you@example.com"
                />
              </div>
              <p className="mt-2 text-sm text-gray-500">
                {React.string(
                   {j|Brief description for your profile. URLs are hyperlinked.|j},
                 )}
              </p>
            </div>
            <div className="mt-6">
              <label
                className="block text-sm leading-5 font-medium text-gray-700">
                {React.string({j|Photo|j})}
              </label>
              <div className="mt-2 flex items-center">
                <span
                  className="inline-block h-12 w-12 rounded-full overflow-hidden bg-gray-100">
                  <svg
                    className="h-full w-full text-gray-300"
                    fill="currentColor"
                    viewBox="0 0 24 24">
                    <path
                      d="M24 20.993V24H0v-2.996A14.977 14.977 0 0112.004 15c4.904 0 9.26 2.354 11.996 5.993zM16.002 8.999a4 4 0 11-8 0 4 4 0 018 0z"
                    />
                  </svg>
                </span>
                <span className="ml-5 rounded-md shadow-sm">
                  <button
                    type_="button"
                    className="py-2 px-3 border border-gray-300 rounded-md text-sm leading-4 font-medium text-gray-700 hover:text-gray-500 focus:outline-none focus:border-blue-300 focus:shadow-outline-blue active:bg-gray-50 active:text-gray-800 transition duration-150 ease-in-out">
                    {React.string({j|Change|j})}
                  </button>
                </span>
              </div>
            </div>
            <div className="mt-6">
              <label
                className="block text-sm leading-5 font-medium text-gray-700">
                {React.string({j|Cover photo|j})}
              </label>
              <div
                className="mt-2 flex justify-center px-6 pt-5 pb-6 border-2 border-gray-300 border-dashed rounded-md">
                <div className="text-center">
                  <svg
                    className="mx-auto h-12 w-12 text-gray-400"
                    stroke="currentColor"
                    fill="none"
                    viewBox="0 0 48 48">
                    <path
                      d="M28 8H12a4 4 0 00-4 4v20m32-12v8m0 0v8a4 4 0 01-4 4H12a4 4 0 01-4-4v-4m32-4l-3.172-3.172a4 4 0 00-5.656 0L28 28M8 32l9.172-9.172a4 4 0 015.656 0L28 28m0 0l4 4m4-24h8m-4-4v8m-12 4h.02"
                      strokeWidth="2"
                      strokeLinecap="round"
                      strokeLinejoin="round"
                    />
                  </svg>
                  <p className="mt-1 text-sm text-gray-600">
                    <button
                      className="font-medium text-indigo-600 hover:text-indigo-500 focus:outline-none focus:underline transition duration-150 ease-in-out">
                      {React.string({j|Upload a file|j})}
                    </button>
                    {React.string({j| or drag and drop|j})}
                  </p>
                  <p className="mt-1 text-xs text-gray-500">
                    {React.string({j|PNG, JPG, GIF up to 10MB|j})}
                  </p>
                </div>
              </div>
            </div>
          </form>
        </div>
      </div>
    </div>
    <div className="py-3 text-right">
      <span className="inline-flex rounded-md shadow-sm">
        <Link
          route={Route.Auth(Register(Choose))}
          className="inline-flex justify-center py-2 px-4 bg-transparent hover:bg-indigo-600 border border-indigo-600 text-sm leading-5 font-medium rounded-md text-indigo-600 hover:text-white focus:outline-none focus:border-indigo-700 focus:shadow-outline-indigo active:bg-indigo-700 transition duration-150 ease-in-out">
          {React.string({j|Cancel|j})}
        </Link>
        <Link
          route=Route.Account
          className="ml-4 inline-flex justify-center py-2 px-4 border border-transparent text-sm leading-5 font-medium rounded-md text-white bg-indigo-600 hover:bg-indigo-500 focus:outline-none focus:border-indigo-700 focus:shadow-outline-indigo active:bg-indigo-700 transition duration-150 ease-in-out">
          {React.string({j|Save|j})}
        </Link>
      </span>
    </div>
  </div>;
};
