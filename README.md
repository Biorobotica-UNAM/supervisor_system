# supervisor_system

## Overview

`supervisor_system` is a ROS 2 package dedicated to monitoring and maintaining the operational integrity of the robotic system at the process level.

Its primary responsibility is to verify that all critical subsystems are active and functioning within the ROS 2 computational graph. In the event of subsystem failure, it autonomously performs process termination and relaunch operations.

This component implements runtime resilience mechanisms within a distributed robotic architecture.

---

## Purpose

The package continuously supervises system-level modules, including but not limited to:

- Vision
- HRI (Human-Robot Interaction)
- Navigation
- Hardware interface
- Manipulation
- Planner
- Executor

Its supervision operates at the ROS graph level — ensuring that required nodes are alive and responsive.

---

## Functional Responsibilities

### 1. Node Presence Verification

The system:

- Inspects the ROS 2 graph.
- Verifies that critical nodes are active.
- Detects unexpected node termination.

This verification ensures system integrity before higher-level modules depend on them.

---

### 2. Failure Handling

If a required module is not detected:

- The process is terminated (if necessary).
- The node or subsystem is relaunched.

This creates a self-healing supervisory layer.

---

### 3. Runtime Stability Enforcement

The package enforces the following principles:

- System-level robustness.
- Autonomous recovery.
- Reduced need for manual intervention.
- Continuous operational readiness.

---

## Architectural Role

`supervisor_system` operates below task-level supervision.  
It ensures that the computational substrate required for plan execution is available.

It does not reason about plans or instructions — only about system operability.

---

## Dependencies

- ROS 2 (rclcpp)
- System process management tools
- Launch interfaces (future integration)

---

## Author: Joshua Martinez

Bio-Robotics Laboratory  
Universidad Nacional Autónoma de México
