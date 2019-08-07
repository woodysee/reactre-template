[@react.component]
let make = (~paths: array(string), ~url: ReasonReactRouter.url) => {
  let currentPath = List.length(url.path) > 0 ? List.nth(url.path, 0) : "";
  let links =
    Array.mapi(
      (i, path: string) => {
        let key = string_of_int(i);
        let linkTitle = path === "" ? "Home" : {j|/$(path)|j};
        let innerLink =
          currentPath === path
            ? <b> {ReasonReact.string(linkTitle)} </b>
            : <span> {ReasonReact.string(linkTitle)} </span>;
        <li key> <a href={j|/$(path)|j}> innerLink </a> </li>;
      },
      paths,
    );
  <section>
    <nav role="navigation"> <ul> {ReasonReact.array(links)} </ul> </nav>
  </section>;
};