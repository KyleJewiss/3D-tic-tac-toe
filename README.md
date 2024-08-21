# 3D-tic-tac-toe
#### **NOTE:** 🚧 This is a work in progress

This is a 2-player, 3 dimensional Tic-Tac-Toe terminal game. It is developed entirely in C++ and is simply a fun side project sharpen my C++ skils 

```bash
          /-----------/|    Layer 3
         /   /   /   / |
        /-----------/  |
       /   /   /   /   |
      /-----------/    |
     /   /   /   /     |
    /-----------/      |
   |       |           |
   |      /-----------/|    Layer 2         
   |     /   /   /   / |                       
   |    /-----------/  |                       
   |   /   /   /   /   |                       
   |  /---------- /    |                      z
   | /   /   /   /     |                      |
   |/-----------/      |                      |
   |       |           |                      |
   |      /-----------/     Layer 1           |________x
   |     /   /   /   /                       /
   |    /-----------/                       /
   |   /   /   /   /                       /
   |  /-----------/                       y
   | /   /   /   /
   |/-----------/
```

The 3D Tic-Tac-Toe grid is customisable from a `2x2x2` grid to... well technically `256x256x256` because the input size is a uint8_t. But anything over a `30x30x30` won't render well in a terminal and to be honest anything over a `5x5x5` is totally impractical to play. To keep with tradition the default size is a `3x3x3` grid, but a `4x4x4` is fun too.