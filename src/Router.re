let paths = [|"", "calculator", "todos"|];

[@react.component]
let make = () => {
  let url: ReasonReactRouter.url = ReasonReactRouter.useUrl();
  let header = <Topnav paths url />;
  let main =
    switch (url.path) {
    | ["calculator"] => <CalculatorPage title="Calculator" />
    | ["todos"] => <TodosPage title="Todo List" />
    | [] => <HomePage title="Home" />
    | _ => <NotFoundPage title="404 Not Found" />
    };
  <section> <header> header </header> <main> main </main> </section>;
};