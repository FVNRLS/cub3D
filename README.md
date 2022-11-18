# cub3D
This project is inspired by the world famous game Wolfenstein 3D, which was the first ever FPS game. With the use of Ray-Casting we created a dynamic view inside a maze in which you'll have to find your way.




https://user-images.githubusercontent.com/88487425/202702073-7153f4c7-e0b2-4b87-a771-48fddbfb68c4.mov




## Getting Started


### Prerequisites

* Installed C compiler like gcc, clang or Cmake
* installed or compiled minilibx

<br>

### On Mac OS


_install brew:_

```
rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update
```

_install glfw:_

```
brew update
brew install glfw
```

_compile and run:_
```
make
make run
```

<br>

### On Debian based Linux distributions


### On Arch Linux


<br>

## Usage

**control**

* W: move forwards
* S: move backwards
* A: move left
* D: move right
* Arrow Key Left: rotate left
* Arrow Key Right: rotate right
* Mouse: rotation control (left-right)
* M: show mouse pointer
* H: hide mouse pointer
* ESC/Q: quit the game

**map customization**

1. Navigate to directory /maps
2. Set textures (directory /textures)
3. Set RGB floor and ceiling colors
4. Set player position on the map




## Roadmap

* Optimize FPS controller


* Add more features:
  * Moving enemies 👾
  * Animated sprites 🌱
  * Implement doors and portals 🟠🏃‍♀️🔵
  * Implement weapons and life-management ⚔️
  * Add menu and sound 


<br>

## Contributing

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement". Don't forget to give the project a star! Thanks again!

<br>

## Acknowledgments

Useful tutorial to understand ray casting:

https://lodev.org/cgtutor/raycasting.html
