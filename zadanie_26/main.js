const { app, ipcMain } = require("electron")
const Window = require("./plugins/Window")
const Menu = require("./plugins/Menu")

win = null

function createMainWindow() {
    const path = `file://${__dirname}/html/index.html`

    win = new Window(path, {
        width: 450,
        height: 220,
        // maxHeight: 620,
        // minHeight: 620,
        // maxWidth: 450,
        // minWidth: 450,
        enableRemoteModule: true,
        preload: `${__dirname}/preloads/mainPreload.js`
    })
    
    win.setMenu(Menu.createMenuFromTemplate())
}


app.on("ready", createMainWindow);
app.on("all-window-closed", () => app.quit());