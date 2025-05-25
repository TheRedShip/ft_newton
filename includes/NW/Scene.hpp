/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:30:18 by ycontre           #+#    #+#             */
/*   Updated: 2025/03/28 16:01:16 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NW_SCENE__HPP
# define NW_SCENE__HPP

# include "NW.hpp"

struct GPUDebug
{
	int	enabled;
	int	mode;
};

class Camera;

class Scene
{
	public:
		Scene();
		~Scene();

		GPUDebug						&getDebug(void);
		Camera							*getCamera(void) const;

	private:
		GPUDebug					_gpu_debug;
		Camera						*_camera;
};

#endif
