type internalState;

type form('parameters, 'result, 'error) = {
  submit: 'parameters => Js.Promise.t(result('result, 'error)),
  mutable internalState,
  isSubmitting: bool,
  isValid: unit => bool,
  validate: unit => bool,
  showErrors: bool,
};

type shouldDisplayError('error) = {
  error: 'error,
  isTouched: bool,
  submitted: bool,
};

type field('a, 'action, 'error) = {
  value: 'a,
  valueForDisplay: result('a, 'error),
  validatedValue: result('a, 'error),
  onChange: 'action => unit,
};

let validatedValueToOpt: field('a, _, _) => option('a);

let useForm:
  (~submit: 'a => Js.Promise.t(result('result, 'error))) =>
  form('a, 'result, 'error);

let useFieldWithReducer:
  (
    ~form: form(_, _, _),
    ~initialValue: 'state,
    'state => result('state, 'error),
    ~displayError: shouldDisplayError('error) => bool=?,
    ('action, 'state) => 'state
  ) =>
  field('state, 'action, 'error);

let useField:
  (
    ~form: form(_, _, _),
    ~initialValue: 'state,
    ~displayError: shouldDisplayError('error) => bool=?,
    'state => result('state, 'error)
  ) =>
  field('state, 'state, 'error);

module ExternalState: {
  type externalState('state) = ('state, ('state => 'state) => unit);

  let useFieldWithReducer:
    (
      ~form: form(_, _, _),
      ~state: externalState('state),
      'state => result('state, 'error),
      ~displayError: shouldDisplayError('error) => bool=?,
      ('action, 'state) => 'state
    ) =>
    field('state, 'action, 'error);

  let useField:
    (
      ~form: form(_, _, _),
      ~state: externalState('state),
      ~displayError: shouldDisplayError('error) => bool=?,
      'state => result('state, 'error)
    ) =>
    field('state, 'state, 'error);
};
