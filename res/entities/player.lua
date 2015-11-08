-- Player entity, that is to say, Chef Excellence
local player = {
    graphics = {
        spriteSheet = "res/chef/chefsheet.png",
        states = {
            stillRight = {
                isAnimated = false,
                frames = {
                    {0, 0, 29, 73}
                }
            },
            stillLeft = {
                isAnimated = false,
                frames = {
                    {30, 0, 29, 73}
                }
            },
            walkingRight = {
                isAnimated = true,
                frames = {
                    {0, 74, 29, 73},
                    {30, 74, 29, 73},
                    {60, 74, 29, 73}
                }
            },
            walkingLeft = {
                isAnimated = true,
                frames = {
                    {0, 148, 29, 73},
                    {30, 148, 29, 73},
                    {60, 148, 29, 73}
                }
            },
            climbing = {
                isAnimated = true,
                frames = {
                    {0, 222, 40, 295},
                    {42, 222, 84, 295}
                }
            }
        }
    }
};

return player;
