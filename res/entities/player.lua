-- Player entity, that is to say, Chef Excellence
local player = {
    userControlled = true,

    graphics = {
        spriteSheet = "res/chef/chefsheet.png",
        isAnimated = true,
        states = {
            { -- Still, right
                stateType = 0,
                frames = {
                    {0, 0, 29, 73},
                    size = 1
                }
            },
            { -- Still, left
                stateType = 1,
                frames = {
                    {30, 0, 29, 73},
                    size = 1
                }
            },
            { -- Walking, right
                stateType = 2,
                frames = {
                    {0, 74, 29, 73},
                    {30, 74, 29, 73},
                    {60, 74, 29, 73},
                    size = 3
                }
            },
            { -- Walking, left
                stateType = 3,
                frames = {
                    {0, 148, 29, 73},
                    {30, 148, 29, 73},
                    {60, 148, 29, 73},
                    size = 3
                }
            },
            { -- Climbing
                stateType = 4,
                frames = {
                    {0, 222, 40, 295},
                    {42, 222, 84, 295},
                    size = 2
                }
            },
            size = 5
        }
    },

    physics = {
        movable = true,
        mass = 10
    }
};

print(player.graphics.stateNumber);

return player;
