
print("INICIANDO ISSO AQUI")

function createPlayer(level,x, y)
	local player = _createObject(level, x, y)
	_addComponent(player, "staticSprite", "img/test.png")
end


function movingObject(obj)
	while 1 do
		_moveTo(obj, 100, 100, 2, 2)
		coroutine.yield()
		_moveTo(obj, 0, 0, -1, -1)
		coroutine.yield()
	end
end

coTest= {}

function testScript(obj)
	if coroutine.status(coTest[obj].behaviour) ~= "dead" then
		coroutine.resume(coTest[obj].behaviour, obj)
	end
end

components = { {type = "playerBehaviour"} ,{type="staticSprite", x = 1, y = 2, w = 32, h = 32, texture = "img/test.png"}, {type = "boxCollider"} }

teste = {{type = "scriptBehaviour"} ,{type="staticSprite", x = 1, y = 2, w = 32, h = 32, texture = "img/test.png"} }

level = _createLevel()

_createObjectExt(level, 23,45,components)

mov = _createObjectExt(level, 0,0,teste)

--behaviour = coroutine.create(movingObject)
coTest = {}
coTest[mov] ={ behaviour = coroutine.create(movingObject)}




--createPlayer(level,100,100)


