const { BrowserWindow } = require('electron')

const defaultSettings = {
    width: 700,
    height: 600,
    title: 'Electron App',
    titleBarStyle: 'hidden',
    frame: true,
    webPreferences: {
      nodeIntegration: true,
      webPreferences: true,
      enableRemoteModule: true,
    },
}

class Window extends BrowserWindow{
    constructor(filePath, userSettings={}){
        super({...defaultSettings, ...userSettings})
        
        this.loadURL(filePath)

        this.once("ready-to-show", () => this.show())
    }
}

module.exports = Window