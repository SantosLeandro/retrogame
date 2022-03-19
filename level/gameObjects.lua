local PlatformComponents = {

    { type = "scriptBehaviour" },
    { type = "staticSprite", x = 1, y = 2, w = 32, h = 32, texture = "img/test.png" },
	{ type = "boxCollider" }

}

local PlayerComponents = {

    { type = "playerBehaviour" },
    { type = "staticSprite", x = 1, y = 2, w = 32, h = 32, texture = "img/test.png" },
    { type = "boxCollider" }

 }

Attributes = {}

ObjectsList= {}

function CreateObject(Level, x, y, Components)
	--o = _createObjectExt(Level, x, y, Components)
	o = {}
	ObjectsList[o] = {life = 100}
	return o
end

obj = CreateObject(nil, 10,10, PlayerComponents)

obj1 = CreateObject(nil, 10,10, PlayerComponents)

obj1.life = 300
print("life obj1",obj1.life)
print("life",ObjectsList[obj1].life)

-- local Components = { 'player' = PayerComponents, 'platform' = PlatformComponents }
Components = {}
Components['player'] = PlayerComponents
Components['platform'] = PlatformComponents

return Components
