// let rec len = (myList: list('a)) =>
//   switch (myList) {
//   | [] => 0
//   | [_, ...tail] => 1 + len(tail)
//   };

/* You're familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
let handleClick = _event => Js.log("clicked!");

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Component1 message="hello" />`

   Which desugars to

   `React.createElement(
     Component1.make,
     Component1.makeProps(~message="hello", ())
   )` */

// let renderTodos = (~todos: array(string)) => {
//   let length: int = Array.length(todos);
//   let todoEls: array(React.element) = [||];
//   for (i in 0 to length) {
//     let todoEl: array(React.element) = [|
//       <li> {ReasonReact.string(todos[i])} </li>,
//     |];
//     let todoEls = Array.append(todoEls, todoEl);
//     ();
//   };
//   todoEls;
// };

[@react.component]
let make = (~title) => {
  let list: array(string) = [|"hello world", "hello world2"|];
  let renderTodo = (todo: string) => {
    <li> {ReasonReact.string(todo)} </li>;
  };
  let renderedTodos = Array.map(renderTodo, list);
  <section>
    <h1> {ReasonReact.string(title)} </h1>
    <ul className="todo-list"> {ReasonReact.array(renderedTodos)} </ul>
  </section>;
};