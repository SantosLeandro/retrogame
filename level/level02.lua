
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

function movingObject2(obj)
	while 1 do
		_moveTo(obj, 400, 400, 1, 1)
		coroutine.yield()
		_moveTo(obj, 0, 0, -1, -1)
		coroutine.yield()
	end
end

coTest= {}

function nextTask(owner, obj)
	if coroutine.status(coTest[owner].behaviour) ~= "dead" then
		coroutine.resume(coTest[owner].behaviour, obj)
	end
end

components = { {type = "playerBehaviour"} ,{type="staticSprite", x = 1, y = 2, w = 32, h = 32, texture = "img/test.png"}, {type = "boxCollider"} }

teste = {{type = "scriptBehaviour"} ,{type="staticSprite", x = 1, y = 2, w = 32, h = 32, texture = "img/test.png"} }

level = _createLevel()

_createObjectExt(level, 23,45,components)

obj1 = _createObjectExt(level, 0,0,teste)
obj2 = _createObjectExt(level, 200,200,teste)

coTest = {}
coTest[obj1] ={ behaviour = coroutine.create(movingObject)}
coTest[obj2] ={ behaviour = coroutine.create(movingObject2)}



--createPlayer(level,100,100)


