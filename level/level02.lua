


function createPlayer(level,x, y)
	local player = _createObject(level, x, y)
	_addComponent(player, "staticSprite", "img/test.png")
end
components = { {type = "playerBehaviour"} ,{type="staticSprite"}, {type = "boxCollider"} }
_createObjectExt(23,45,components)

level = _createLevel()
createPlayer(level,100,100)


