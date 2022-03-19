--Room = require("./level/room")

Components = require("./level/gameObjects")
require("./level/room")
--local components = require('./level/gameObjects')
--
local room = Room:new()

room:addObject({},{x = 23, y = 45},Components['player'])
--local level = _createLevel()
