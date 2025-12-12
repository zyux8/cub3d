/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycast.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbarthol <pbarthol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:43:24 by pbarthol          #+#    #+#             */
/*   Updated: 2025/12/11 21:40:55 by pbarthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCAST_H
# define CUB3D_RAYCAST_H

# include "cub3d.h"

# define PI 3.141592653589f

typedef	struct s_raycast_data
{
	float	fov;
}	t_raycast_data;

/**
 * Required data:
 * - player_pos (x, y)
 * - player_dir (radians)
 * - screen_width (pixels)
 */

typedef	struct s_player_data
{
	int		player_x;
	int		player_y;
	float	player_dir;
}	t_player_data;

/**
 * Calculations for raytracing:
 * 
 * To get the viewingDirection we have to convert playerAngle from degrees to
 * radians. 360 degrees equals 2 x PI. Conversion look like this:
 * 
 * - degrees -> radians:
 * 		rad = deg * (PI / 180)
 * - radians -> degrees:
 * 		deg = rad * (180 / PI)
 * 
 * Next thing is the FOV. The maximum FOV is 180 deg, a normal. To calculate the
 * FOV devide 180 by the target FOV in deg. Then devide PI by this and you get
 * the FOV in radians.
 * 
 * 		x = 180 / targetFOV
 * 		FOV = PI / x
 * 
 * Now we calculate the angle that every ray should have from the playerPos. For
 * that we need the screenWidth in pixels. Every column on the screen gets it's
 * own ray. The camera plain is perpendicular to the playerDir. So to start from
 * the left we take playerAngle and subtract half of the FOV. Now we add x times
 * FOV devided by the screenWidth. x is the columns we want to draw. By dividing
 * FOV by the screenWidth we get the number of columns we have. By adding this
 * times x to the furthest left angle we get the rayAngle for every column.
 * 
 * 		rayAngle = playerAngle - (FOV / 2) + x * (FOV / screenWidth)
 * 
 * To convert the rayAngle into movement direction we use sine and cosine of
 * rayAngle. For the X direction it's cosine and for Y it's sine.
 * 
 * 		rayDirX = cos(rayAngle)
 * 		rayDirY = sin(rayAngle)
 * 
 * Taking rayDir by t and adding it to the playerPos the ray moves forward. In
 * this case t is the distance traveled. We again do this for X and Y.
 * 
 * 		rayX = playerPosX + rayDirX * t
 * 		rayY = playerPosY + rayDirY * t
 * 
 * Next up is to add grid stepping. Because the rays travel through the grid not
 * only horizontally and vertically but in different angles, the distance to the
 * next grid line is allways different. To compansate for that calculate the
 * distance a ray has to travel to hit the next grid line with the rayDir.
 * 
 * 		deltaDistX = |1 / rayDirX|
 * 		deltaDistY = |1 / rayDirY|
 * 
 * Because the player can move freely on the grid the distance to the first grid
 * line is allways different. If we just go with the grid steppig now we have an
 * offset and grid line distances are not being calulated correctly. Depending
 * on the direction the ray travels in we use floor() and ceil() functions from
 * the math.h library. These functions round a number to the next integer either
 * up or down. If the direction is > 0 we use ceil(), if it is < 0 we use
 * floor(). Depending on the direction we take playerPos and the result and
 * subtract the larger from the smaller number. That is the difference is the
 * first t. After that we continue with the grid stepping.
 * 
 * 	- rayDirX > 0
 * 		initialX = playerPosX - ceil(playerPosX)
 * 	- rayDirX < 0
 * 		initialX = floor(playerPosX) - playerPosX
 * 	- rayDirY > 0
 * 		initialY = playerPosY - ceil(playerPosY)
 * 	- rayDirY < 0
 * 		initialY = floor(playerPosY) - playerPosY
 * 
 * Now we compare if the X distance or Y distance is shorter. Then the ray
 * travels to the next grid line and check if it is a wall. As soon as we hit a
 * wall we draw a line in that column. For double the distance the wall should
 * be half the size. Expamle:
 * 
 * 		Distance = 1u - height = 4
 * 		Distance = 2u - height = 2
 * 		Distance = 4u - height = 1
 * 		Distance = 8u - height = 0.5
 * 
 * Last thing to do is to correct the fish-eye optic. For that we use cosine
 * again.
 * 
 * 		correctedDistance = wallDistance * cos(rayAngle - playerAngle)
 * 
 * We continue this for every column until the image is rendered.
 */

#endif
