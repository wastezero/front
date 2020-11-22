type t = Protocol_v1_t.address;

let toString: t => string =
  address => {
    address.street ++ " " ++ address.house_number ++ ", " ++ address.city_name;
  };
