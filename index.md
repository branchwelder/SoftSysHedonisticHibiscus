# Lá Trop
## Now you're thinking with OpenGL, teleportation, and gravity!
### Hannah Twigg-Smith, Philip Seger, Sam Myers

## What we did
We implemented a game using OpenGL in C++. This game consists of a player who can place two portals which teleport the player to the other location on contact. The world where this player exists is affected by gravity and other obstacles, however they can jump around and teleport to solve levels.

## What we set out to accomplish
The main goal of this project was to develop a game in C++ using OpenGL to render sprites and graphics. The finished game consists of player movement from a two-dimensional, top-down perspective. A mechanic we implemented was portals that allow the player to teleport to different locations. Stretch goals that we met were improved graphics using textures and a more lifelike physics engine that includes gravity on the player.

## How we planned on accomplishing it
Our [sprint plan](https://github.com/hannahtwiggsmith/SoftSysHedonisticHibiscus/projects/1) can be viewed on GitHub projects. We organized our work using this system, as it is fairly new and we wanted to try it out.

We wanted to explore video game development from a lower level instead of using some existing frameworks, such as Pygame or Unity. As such, we decided to use some older technology (GLUT's most "recent" release was sometime pre-2000s). This meant we had to learn about frame redraw and some of the logic behind rendering, as well as polygons and textures, without cheating by using a framework that easily rendered objects for us. Much of the knowledge we gained for this we found at [this tutorial](http://www.lighthouse3d.com/tutorials/glut-tutorial/). Once we got around the behemoth of a problem that was implementing things using GLUT, a lot of our work was more manageable with the knowledge we gained about [C++](https://learnxinyminutes.com/docs/c++/). From there, physics was a bit of loosey-goosey math and we built on from there in similar fashion.

## What was accomplished
We set out to implement some core features that are found in games. Player movement is done with the A and D keys, while jumping is accomplished with W. Q and E fire a portal, and if you already have one Q portal on the map, pressing Q again will replace the position to an updated location next to the player. Levels are stored as .txt files and can be edited by the end user to create custom and unique maps. In these files, 0s represent blank space, while 1s represent a block. The player always starts in the same position, however if they have no ground under them they will fall because of physics. For more in-depth explanation about some of the extra features we worked on, continue reading.

### _OpenGL graphics and textures_
The largest focus for this project was exploring and learning about OpenGL and GLUT, rendering systems that are available for many languages, but in this case more in the context of C++. With GLUT/OpenGL, the main loop takes over the program (using `glutMainLoop()`) and is the reason for frame redraws and updates. This updates the model and renders the view every time it runs through the game loop.

This way of thinking of course caused us some initial trouble. For example, once the glut main loop starts running, printing to std::cout does not work as expected (as the main glut loop never returns). As such, we thought everything was constantly broken because all the debug messages were never showing up. However, once we had a grasp of the `glutMainLoop()`, we were set.

Another component we worked with was SOIL (simple OpenGL image library) in OpenGL. SOIL is much more straightforward than the "pure" OpenGL way of rendering textures, which made our lives considerably easier (~5 lines of code with SOIL vs. ~300 lines without). This meant that we could create a player texture and render it with this code:
```
_tex = SOIL_load_OGL_texture
    (
     "doge.jpg",
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
```
This code loads the texture and stores it, which is then rendered onto a polygon with the following code:
```
// Enable 2D textures
glEnable(GL_TEXTURE_2D);

// Bind texture to the texture target (GL_TEXTURE_2D)
glBindTexture(GL_TEXTURE_2D, _tex);

// Create a coord and bind it to the vertex
glBegin(GL_POLYGON);
glColor3f(255,255,255);
glTexCoord2f(0,0);
glVertex2f(_x,_y);
glTexCoord2f(1,0);
glVertex2f(_x+1, _y);
glTexCoord2f(1,1);
glVertex2f(_x+1, _y+1);
glTexCoord2f(0,1);
glVertex2f(_x, _y+1);
glEnd();
```

### _Physics_
Instead of handling player movement as a discrete number of blocks per keypress, we switched to players having acceleration and velocities, making movement seem a little more fluid. The way we process keypresses now sets the velocity of a player, as shown below:
```
void Model::_processKeys() {
    if (_keyStates['a'] && !_keyStates['d']) {
        _player.setActiveVelocity(-PLAYER_SPEED, 0.0f);
    } else if (_keyStates['d'] && !_keyStates['a']) {
        _player.setActiveVelocity(PLAYER_SPEED, 0.0f);
    } else {
        _player.setActiveVelocity(0.0f, 0.0f);
    }
}
```

As well, we process gravity if there is no block underneath the player. This is a meaty function, but the big takeaways are that there is a dy/dt multiplier for gravity, and this affects the player no matter where they are, unless they are on the bottom of the map or intersecting with another block.

```
void Model::_handlePhysics(float dt) {
    float dydt = GRAVITY * (dt / 1000.0f);
    double dx = _player.getVelocity().first * (dt / 1000.0f);
    double dy = (_player.getVelocity().second + dydt) * (dt / 1000.0f);
    Position newPosition = Position(
        _player.getPosition().first + dx,
        _player.getPosition().second + dy
    );

    bool xCollision = false;
    bool yCollision = false;
    for (auto it : _world) {
        int collision = _checkCollision(it.first, newPosition);
        if (collision == 1 && !xCollision) {
            xCollision = true;
            dx += _handleCollision(newPosition.first, it.first.first);
        }
        if (collision == 2 && !yCollision) {
            yCollision = true;
            dy += _handleCollision(newPosition.second, it.first.second);
        }
        if (xCollision && yCollision) {
            break;
        }
    }

    if (yCollision) {
        if (!_player.onGround) {
            _player.onGround = true;
            _player.resetPassiveVelocity();
        }
    } else {
        if (_player.onGround) {
            _player.onGround = false;
        }
        _player.changePassiveVelocity(0.0f, dydt);
    }

    _movePlayer(dx, dy);
}
```

### _Developing in Xcode_
Every member of the team had a Mac, so we decided as a team that this might be an opportune time to learn the ins and outs of Xcode. To do this, we built the whole project in the environment, using the command line as little as possible to fully immerse ourselves. This turned out to be a bit of a double edged sword. While it was super useful to compile and run the game, it also meant that we did not have a way to build for other environments as easily. As well, a merge conflict with Xcode project configuration settings turned into a monster that was not as easily resolved. In general though, C++ development with Xcode was fairly straightforward and very nice for building a test package without much extra thought (just use CMD+r).

### _C++ instead of C_
We also approached this project more in the mindset of using C++ instead of C. As it turns out, the object-oriented paradigm is better suited for game development than pure C. Mainly, we used public and private values and functions to more conveniently organize code. We also split up files into the Model, View, Control model that is standard in all game programming.

## The completed game
A more complete look at the game can be found in [our repo](https://github.com/hannahtwiggsmith/SoftSysHedonisticHibiscus). However, if clicking links is too difficult, don't worry, here is a gif of the player falling because of gravity.

![gravity.gif](reports/resources/gravity.gif)
