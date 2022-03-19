
Room = { objects = {} }
function Room:new(o)
	o = o or {}
	setmetatable(o, self)
	self.__index = self
	self.levelPtr = _createLevel()
	self.objects = {}
	return o
end

function Room:addObject(object, position,components)
	local ptr = _createObject(self.levelPtr,position.x,position.y,components)
	self.objects[ptr] = object
end

function Room:getPtr()
	return self.levelPtr
end

function Room:getObject(ptr)
	return self.objects[ptr]
end

return Room
