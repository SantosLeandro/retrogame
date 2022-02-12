


function createPlayer(level,x, y)
	local player = _createObject(level, x, y)
	_addComponent(player, "staticSprite", "img/test.png")
end
components = { {type = "playerBehaviour"} ,{type="staticSprite", x = 1, y = 2, w = 32, h = 32, texture = "img/test.png"}, {type = "boxCollider"} }

level = _createLevel()

_createObjectExt(level, 23,45,components)


createPlayer(level,100,100)


