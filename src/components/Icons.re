module HeroIcons = {
  module Home = {
    [@bs.module "assets/icons/heroicons/outline/home.svg"] [@react.component]
    external make: (~className: string=?, unit) => React.element = "default";
  };

  module Clock = {
    [@bs.module "assets/icons/heroicons/outline/clock.svg"] [@react.component]
    external make: (~className: string=?, unit) => React.element = "default";
  };

  module CreditCard = {
    [@bs.module "assets/icons/heroicons/outline/credit-card.svg"]
    [@react.component]
    external make: (~className: string=?, unit) => React.element = "default";
  };

  module Bell = {
    [@bs.module "assets/icons/heroicons/outline/bell.svg"] [@react.component]
    external make: (~className: string=?, unit) => React.element = "default";
  };

  module QuestionMarkCircle = {
    [@bs.module "assets/icons/heroicons/outline/question-mark-circle.svg"]
    [@react.component]
    external make: (~className: string=?, unit) => React.element = "default";
  };

  module MenuAlt1 = {
    [@bs.module "assets/icons/heroicons/outline/menu-alt-1.svg"]
    [@react.component]
    external make: (~className: string=?, unit) => React.element = "default";
  };

  module ChevronDown = {
    [@bs.module "assets/icons/heroicons/solid/chevron-down.svg"]
    [@react.component]
    external make: (~className: string=?, unit) => React.element = "default";
  };

  module X = {
    [@bs.module "assets/icons/heroicons/outline/x.svg"] [@react.component]
    external make: (~className: string=?, unit) => React.element = "default";
  };
};

module ManagerIllustration = {
  [@bs.module "assets/icons/manager_illustration.svg"] [@react.component]
  external make: (~className: string=?, unit) => React.element = "default";
};
