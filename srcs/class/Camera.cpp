/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:00:38 by TheRed            #+#    #+#             */
/*   Updated: 2025/03/17 12:03:09 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Camera.hpp"

Camera::Camera(glm::vec3 start_pos, glm::vec3 start_up, float start_yaw, float start_pitch)
			:  _position(start_pos), _forward(glm::vec3(0.0f, 0.0f, -1.0f)), _up(start_up), _pitch(start_pitch), _yaw(start_yaw),
				_velocity(0.0f), _acceleration(0.0f)
{
	updateCameraVectors();
}

Camera::~Camera(void)
{
}

void		Camera::updateCameraVectors()
{
	glm::vec3 frontTemp;

	frontTemp.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
	frontTemp.y = sin(glm::radians(_pitch));
	frontTemp.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
	_forward = glm::normalize(frontTemp);

	_right = glm::normalize(glm::cross(_forward, glm::vec3(0.0f, 1.0f, 0.0f)));
	_up = glm::normalize(glm::cross(_right, _forward));
}

void Camera::updateCameraDirections()
{
    float new_yaw = glm::degrees(atan2(-_forward.x, _forward.z));
    if (new_yaw < 0.0f)
        new_yaw += 360.0f;

    float old_yaw_mod = fmod(_yaw, 360.0f);
    if (old_yaw_mod < 0.0f)
        old_yaw_mod += 360.0f;

    float delta_yaw = new_yaw - old_yaw_mod;
    if (delta_yaw > 180.0f)
        delta_yaw -= 360.0f;
    else if (delta_yaw < -180.0f)
        delta_yaw += 360.0f;

    _yaw += delta_yaw + 90.0f;

    _pitch = glm::degrees(asin(_forward.y));
    _pitch = glm::clamp(_pitch, -89.0f, 89.0f);
}

void		Camera::update(float delta_time)
{
	// delta_time = std::min(delta_time, 0.01f);

	_velocity += _acceleration * delta_time;

	if (glm::length(_acceleration) < 0.1f)
		_velocity *= std::max(0.0f, 1.0f - _deceleration_rate * delta_time);
	
	float speed = glm::length(_velocity);
	if (speed > _maxSpeed)
		_velocity = glm::normalize(_velocity) * _maxSpeed;
	
	if (glm::length(_velocity) > 0.0f)
		_position += _velocity * delta_time;

	_acceleration = glm::vec3(0.0f);
}

void		Camera::processMouse(float xoffset, float yoffset, bool constraint_pitch = true)
{
	_yaw   += xoffset * _sensitivity;
	_pitch += yoffset * _sensitivity;

	if (constraint_pitch)
	{
		if (_pitch > 89.0f) _pitch = 89.0f;
		if (_pitch < -89.0f) _pitch = -89.0f;
	}

	updateCameraVectors();
}

void		Camera::processKeyboard(bool forward, bool backward, bool left, bool right, bool up, bool down)
{
	glm::vec3 acceleration(0.0f);

	if (forward)  acceleration += _forward;
	if (backward) acceleration -= _forward;
	if (right)    acceleration += _right;
	if (left)     acceleration -= _right;
	if (up)       acceleration += _up;
	if (down)     acceleration -= _up;
	
	if (glm::length(acceleration) > 0.1f)
		acceleration = glm::normalize(acceleration) * _acceleration_rate;
	
	_acceleration = acceleration;
}

glm::mat4	Camera::getViewMatrix()
{
	return (glm::lookAt(_position, _position + _forward, _up));
}

glm::vec3	Camera::getPosition()
{
	return (_position);
}

glm::vec2	Camera::getDirection()
{
	return (glm::vec2(_pitch, _yaw));
}

float		Camera::getVelocity()
{
	return (glm::length(_velocity));
}

float		&Camera::getFov()
{
	return (_fov);
}

void		Camera::setPosition(glm::vec3 position)
{
	_position = position;
}

void		Camera::setDirection(float pitch, float yaw)
{
	_pitch = pitch;
	_yaw = yaw;
	updateCameraVectors();
}

void		Camera::setFov(float fov)
{
	_fov = fov;
}
