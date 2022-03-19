Components = require("./level/gameObjects")

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

        _moveTo(obj, 400, 0, 1, 0)

        coroutine.yield()

        _moveTo(obj, 0, 0, 0, -1)

        coroutine.yield()

    end

end


function nextTask(owner, compPtr)

    if coroutine.status(Behaviour[owner].behaviour) ~= "dead" then

        coroutine.resume(Behaviour[owner].behaviour, compPtr)

    end
end

local level = _createLevel()

Player = _createObjectExt(level, 23, 45, Components['player'])

Obj1 = _createObjectExt(level, 0, 0, Components['platform'])

Obj2 = _createObjectExt(level, 0, 0, Components['platform'])

Behaviour = {}

Behaviour[Obj1] = { behaviour = coroutine.create(movingObject) }

Behaviour[Obj2] = { behaviour = coroutine.create(movingObject2) }
