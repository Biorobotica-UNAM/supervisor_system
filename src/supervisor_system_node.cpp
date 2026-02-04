#include <rclcpp/rclcpp.hpp>
#include <vector>
#include <string>

#include "supervisor_interfaces/msg/system_status.hpp"

using namespace std::chrono_literals;

class SystemStatusPublisher : public rclcpp::Node
{
public:
  SystemStatusPublisher()
  : Node("system_status_publisher")
  {
    publisher_ = this->create_publisher<
      supervisor_interfaces::msg::SystemStatus
    >("/system/status", 10);

    timer_ = this->create_wall_timer(
      1s,
      std::bind(&SystemStatusPublisher::publishStatus, this)
    );

    RCLCPP_INFO(this->get_logger(), "Supervisor system: started");
  }

private:
  void publishStatus()
  {
    supervisor_interfaces::msg::SystemStatus msg;

    // ===== Todo OK =====
    msg.navigation    = true;
    msg.manipulation  = true;
    msg.vision        = true;
    msg.hri           = true;
    msg.executor      = true;
    msg.planner       = true;
    msg.hardware      = true;

    // ===== Módulos activos =====
    msg.active_modules = {
      "navigation",
      "manipulation",
      "vision",
      "hri",
      "executor",
      "planner",
      "hardware"
    };

    publisher_->publish(msg);
  }

  rclcpp::Publisher<supervisor_interfaces::msg::SystemStatus>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SystemStatusPublisher>());
  rclcpp::shutdown();
  return 0;
}
