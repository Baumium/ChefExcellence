-- Graphics
backgroundSrc = "res/map/level1/background.png";


-- Allow us to access lua files in the entities directory
package.path = package.path .. ";../../entities/?.lua";
entities = {};

player = require("res/entities/player");
entities[1] = {
    player,
    x = 50,
    y = 50,
    action = 0,
    direction = 0
};

entitiesSize = #entities;
