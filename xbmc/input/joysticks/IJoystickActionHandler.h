/*
 *      Copyright (C) 2014 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "JoystickTypes.h"

#include <vector>

/*!
 * \ingroup joysticks
 * \brief Interface defining all supported joystick action events
 */
class IJoystickActionHandler
{
public:
  virtual ~IJoystickActionHandler(void) { }

  /*!
   * \brief A button has been pressed
   *
   * \param id        The ID of the button or trigger
   * \param bPressed  The new state of the button or trigger
   *
   * \return True if the event was handled otherwise false
   */
  virtual bool OnButtonPress(JoystickActionID id) { return false; }

  /*!
   * \brief A pressure-sensitive button has been pressed or a trigger has moved
   *
   * \param id        The ID of the button or trigger
   * \param magnitude The button pressure or trigger travel distance in the interval [0, 1]
   *
   * \return True if the event was handled otherwise false
   */
  virtual bool OnButtonMotion(JoystickActionID id, float magnitude) { return false; }

  /*!
   * \brief A button has been held past a timeout
   *
   * \param id        The ID of the button or trigger
   *
   * \return True if the event was handled otherwise false
   */
  virtual bool OnButtonHold(JoystickActionID id) { return false; }

  /*!
   * \brief A button has been pressed twice within a small timeframe
   *
   * \param id        The ID of the button or trigger
   *
   * \return True if the event was handled otherwise false
   */
  virtual bool OnButtonDoublePress(JoystickActionID id) { return false; }

  /*!
   * \brief Multiple buttons have been pressed within a small timeframe
   *
   * \param ids        The IDs in order of pressed
   *
   * \return True if the event was handled otherwise false
   */
  virtual bool OnMultiPress(const std::vector<JoystickActionID>& ids) { return false; }

  /*!
   * \brief A button has been released
   *
   * \param id        The ID of the button or trigger
   *
   * \return True if the event was handled otherwise false
   */
  virtual bool OnButtonRelease(JoystickActionID id) { return false; }

  /*!
   * \brief An analog stick has moved
   *
   * \param id        The ID of the analog stick
   * \param x         The x coordinate in the closed interval [-1, 1]
   * \param y         The y coordinate in the closed interval [-1, 1]
   *
   * \return True if the event was handled otherwise false
   */
  virtual bool OnAnalogStickMotion(JoystickActionID id, float x, float y) { return false; }

  /*!
   * \brief An accelerometer's acceleration has changed
   *
   * \param x         The x coordinate in the closed interval [-1, 1]
   * \param y         The y coordinate in the closed interval [-1, 1]
   * \param z         The z coordinate in the closed interval [-1, 1]
   *
   * \return True if the event was handled otherwise false
   */
  virtual bool OnAccelerometerMotion(JoystickActionID id, float x, float y, float z) { return false; }
};
