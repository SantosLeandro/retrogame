Components = require("./level/gameObjects")

Room = require("./level/room")


print("MAIN.LUA")

local room1 = Room:new({

})

local room = room1

function OnRoomLeave()

end

function OnCollisionEnter(obj, other)
	room:getObject(obj).onCollision(obj, other)
end

function NextTask(obj, componentPtr)
	_moveTo(obj, 300,300,2,2)
	print("next task")
end

function Inc(value, inc)
	value = value + inc
	return value
end

local player = { name = 'player' }

local platform = { count = 0 }
function platform.onCollision(obj, other)
	local o = room:getObject(other)
	local this = room:getObject(obj)
	if(o.name == 'player') then
		this.count = this.count + 1
		print("opa algo aconteceu aqui",this.count)
	end
end


room1:addObject(player,{x = 23, y = 45},Components['player'])
room1:addObject(platform,{x=100,y=100},Components['platform'])

