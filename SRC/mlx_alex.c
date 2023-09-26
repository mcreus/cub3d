/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_alex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <mcreus@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:45:41 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/25 11:30:30 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void     background(t_data *data)
{
    int     i;
    int     j;
    int     ceil;
    int     floo;

    i = 0;
    ceil = (data->ceiling.r << 16 | data->ceiling.g << 8 | data->ceiling.b);
    floo = (data->floor.r << 16 | data->floor.g << 8 | data->floor.b);

    while (i < (HEIGHT / 2))
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(&data->img_f, j++, i, ceil);
		}
		++i;
	}
    while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(&data->img_f, j++, i, floo);
		}
		++i;
	}
}

void	test_ray(t_data *data)
{
  double posX = 2, posY = 1;  //x and y start position
  double dirX = -1, dirY = 0; //initial direction vector
  double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

  //while(!done())
 // {
    for(int x = 0; x < WIDTH; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;
      //which box of the map we're in
      int mapX = (int)posX;
      int mapY = (int)posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      //these are derived as:
      //deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
      //deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
      //which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
      //where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
      //unlike (dirX, dirY) is not 1, however this does not matter, only the
      //ratio between deltaDistX and deltaDistY matters, due to the way the DDA
      //stepping further below works. So the values can be computed as below.
      // Division through zero is prevented, even though technically that's not
      // needed in C++ with IEEE 754 floating point values.
      //double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
      //double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);

      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if(rayDirX < 0)
      {
 	    stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
      //perform DDA
      while(hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(data->map[mapY][mapX] == '1') 
			hit = 1;
      }
	if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(HEIGHT/ perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + HEIGHT / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + HEIGHT / 2;
      if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

      //choose wall color
      int color;
      switch(data->map[mapY][mapX])
      {
        case 1:  color = 16711680;    break; //red
        case 2:  color = 65280;  break; //green
        case 3:  color = 255;   break; //blue
        case 4:  color = 16777215;  break; //white
        default: color = 16776960; break; //yellow
      }

      //give x and y sides different brightness
      if(side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      //verLine(x, drawStart, drawEnd, color);
	  while (drawStart < drawEnd)
	  {
		img_pix_put(&data->img_f, x, drawStart++, color);
	  }
    }
	/*
    //timing for input and FPS counter
    oldTime = time;
    time = getTicks();
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    print(1.0 / frameTime); //FPS counter
    redraw();
    cls();

    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
    readKeys();
    //move forward if no wall in front of you
    if(keyDown(SDLK_UP))
    {
      if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if(keyDown(SDLK_DOWN))
    {
      if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    }
    //rotate to the right
    if(keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if(keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
	*/
  }

//}

int		view(t_data *data)
{
	if (!data->win)
        return (1);
	background(data);
	test_ray(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_f.mlx_img, 0, 0);
    return (0);
}

void    game_init(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
		return ;
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
    if (!data->win)
		return ;
	
    data->img_f.mlx_img = mlx_new_image(data->mlx,WIDTH , HEIGHT);
    data->img_f.addr = mlx_get_data_addr(data->img_f.mlx_img, &data->img_f.bpp,
                &data->img_f.line_len, &data->img_f.endian);


    mlx_loop_hook(data->mlx, &view, data);
	//mlx_hook(data->win, 17, 0, &end_window, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_input, data);
	mlx_loop(data->mlx);
	mlx_destroy_image(data->mlx, data->img_f.mlx_img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
