[@react.component]
let make = (~title: string) => {
  <section> <h1> {ReasonReact.string(title)} </h1> </section>;
};