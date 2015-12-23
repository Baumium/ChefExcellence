-- Graphics
backgroundSrc = "res/map/level1/background.png";


-- Allow us to access lua files in the entities directory
package.path = package.path .. ";../../entities/?.lua";
entities = {};

player = require("res/entities/player");
entities[1] = {
    player,
    x = 0,
    y = 0
};

entitiesSize = #entities;
