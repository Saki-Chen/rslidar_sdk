/******************************************************************************
 * Copyright 2020 RoboSense All rights reserved.
 * Suteng Innovation Technology Co., Ltd. www.robosense.ai

 * This software is provided to you directly by RoboSense and might
 * only be used to access RoboSense LiDAR. Any compilation,
 * modification, exploration, reproduction and redistribution are
 * restricted without RoboSense's prior consent.

 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOSENSE BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#pragma once

#include "interface/lidar_base.h"
#include "utility/yaml_reader.hpp"
#include "msg/rs_msg/lidar_packet_msg.h"
#include "msg/rs_msg/lidar_scan_msg.h"

namespace robosense
{
    namespace lidar
    {
        /**
 * @brief Lidar packets message interface
 * @detail 1, Will be inheritted by Lidar packets ROS message adapter
 *         2, Will be inheritted by driver base which relate to Lidar packets messages(eg: LidarBase)
 */
        class LidarPacketsInterface : virtual public LidarBase
        {
        public:
            LidarPacketsInterface() = default;
            virtual ~LidarPacketsInterface() = default;

            /**
  * @brief initialize function
  * @param config--yaml node
  */
            virtual void init(const YAML::Node &config) = 0;
            /**
  * @brief start function
  */
            virtual void start() = 0;
            /**
  * @brief stop function
  */
            virtual void stop() = 0;
            /**
  * @brief send function
  * @detail send lidar msop packets message through ROS
  * @param msg--the Robosense LidarScanMsg message
  */
            virtual void send_msop(const LidarScanMsg &msg) {}
            /**
  * @brief send function
  * @detail send lidar difop packet message through ROS
  * @param msg--the Robosense LidarPacketMsg message
  */
            virtual void send_difop(const LidarPacketMsg &msg) {}
            /**
  * @brief register receive call back function
  * @detail after registration, the Lidar module can pass lidar msop packet message to other module
  * @param callBack--the function pointer of the call back function
  */
            virtual void regRecvCallback(const std::function<void(const LidarScanMsg &)> callBack) = 0;
            /**
  * @brief register receive call back function
  * @detail after registration, the Lidar module can pass lidar difop packet message to other module
  * @param callBack--the function pointer of the call back function
  */
            virtual void regRecvCallback(const std::function<void(const LidarPacketMsg &)> callBack) = 0;
        };
    } // namespace lidar
} // namespace robosense
