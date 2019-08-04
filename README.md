# React Reason Template

## Run Project

```sh
npm install
npm start
# in another tab
# Either...
npm run webpack
# Or if you are running while developing,
# run this instead:
npm run server
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up `build/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.

**For more elaborate ReasonReact examples**, please see <https://github.com/reasonml-community/reason-react-example>

## Run Project with Server

To run with the webpack development server run `npm run server` and view in the browser at <http://localhost:8000.> Running in this environment provides hot reloading and support for routing; just edit and save the file and the browser will automatically refresh.

Note that any hot reload on a route will fall back to the root (`/`), so `ReasonReact.Router.dangerouslyGetInitialUrl` will likely be needed alongside the `ReasonReact.Router.watchUrl` logic to handle routing correctly on hot reload refreshes or simply opening the app at a URL that is not the root.

To use a port other than 8000 set the `PORT` environment variable (`PORT=8080 npm run server`).

## Build for Production

```sh
npm run clean
npm run build
npm run webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version as well as copy `src/index.html` into `build/`. You can then deploy the contents of the `build` directory (`index.html` and `Index.js`).

If you make use of routing (via `ReasonReact.Router` or similar logic) ensure that server-side routing handles your routes or that 404's are directed back to `index.html` (which is how the dev server is set up).

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.

## Dev log

### My first encounter with OCaml

I don't originally have OCaml set up so I had to get everything sorted out first.

- Install [`opam`](https://opam.ocaml.org/doc/Install.html#Using-your-distribution-39-s-package-system), which is the package manager for OCaml via your system's package manager (e.g. Homebrew).
- Run `opam install merlin`. Merlin is required if you want to use `reason-vscode` in Visual Studio Code.
- Run `opam user-setup install` after, along with its dependencies.
- Install the [recommended](https://reasonml.github.io/docs/en/editor-plugins) [`reason-vscode`](https://marketplace.visualstudio.com/items?itemName=jaredly.reason-vscode) package, if you are using Visual Studio Code.

### Creating a new component

Components seem to be created by creating a new `.re` file in pascal case. There seems to be no way to set up how the app imports the components manually.
