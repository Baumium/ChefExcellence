-- Player entity, that is to say, Chef Excellence
local player = {
    graphics = {
        spriteSheet = "res/chef/chefsheet.png",
        isAnimated = true,
        states = {
            { -- Still, right
                action = 0,
                direction = 1,
                frames = {
                    {0, 0, 29, 73},
                    size = 1
                }
            },
            { -- Still, left
                action = 0,
                direction = 0,
                frames = {
                    {30, 0, 29, 73},
                    size = 1
                }
            },
            { -- Walking, right
                action = 1,
                direction = 1,
                frames = {
                    {0, 74, 29, 73},
                    {30, 74, 29, 73},
                    {60, 74, 29, 73},
                    size = 3
                }
            },
            { -- Walking, left
                action = 1,
                direction = 0,
                frames = {
                    {0, 148, 29, 73},
                    {30, 148, 29, 73},
                    {60, 148, 29, 73},
                    size = 3
                }
            },
            { -- Climbing up
                action = 3,
                direction = 2,
                frames = {
                    {0, 222, 40, 295},
                    {42, 222, 84, 295},
                    size = 2
                }
            },
            { -- Climbing down
                action = 3,
                direction = 3,
                frames = {
                    {0, 222, 40, 295},
                    {42, 222, 84, 295},
                    size = 2
                }
            },
            size = 6
        }
    },

    physics = {
        canMove = true,
        canFall = true,
        mass = 10.0
    },

    control = {
        userControlled = true,
        up = 22,
        down = 17,
        left = 0,
        right = 3
    }
};

print(player.graphics.stateNumber);

return player;
