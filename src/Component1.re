type todo = {
  text: string,
  isDone: bool,
};

let initialTodos: array(todo) = [|
  {text: "Wash clothes", isDone: true},
  {text: "Buy dinner", isDone: false},
  {text: "Learn ReasonReact", isDone: false},
|];

[@react.component]
let make = (~title) => {
  let (todos, setTodos) = React.useState(() => initialTodos);
  let toggleTaskCompletion = (key, ~currTodo) => {
    Js.log(string_of_int(key) ++ string_of_bool(currTodo.isDone));
    setTodos(prevTodos => {
      let updatedTodos = Array.copy(prevTodos);
      updatedTodos[key] = {...currTodo, isDone: !currTodo.isDone};
      updatedTodos;
    });
  };

  let renderTodo = (key: int, {text, isDone}: todo) => {
    let toggleCheckbox = _event =>
      toggleTaskCompletion(key, ~currTodo={text, isDone});
    let todoId = string_of_int(key);
    <li key=todoId>
      <input type_="checkbox" checked=isDone onChange=toggleCheckbox />
      {ReasonReact.string(text)}
    </li>;
  };
  let renderedTodos =
    Array.mapi((i, renderedTodo) => renderTodo(i, renderedTodo), todos);
  <section>
    <h1> {ReasonReact.string(title)} </h1>
    <ul className="todo-list"> {ReasonReact.array(renderedTodos)} </ul>
  </section>;
};