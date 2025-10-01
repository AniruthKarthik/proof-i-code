#include "uss.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

SensorData read_sensors()
{
	SensorData data;

	data.front = rand() % 100;
	data.back = rand() % 100;
	data.left = rand() % 100;
	data.right = rand() % 100;

	return data;
}

void execute_movement(Direction dir)
{
	switch (dir)
	{
	case DIR_NORTH:
		printf(">>> Moving NORTH (Forward)\n");
		break;
	case DIR_SOUTH:
		printf(">>> Moving SOUTH (Backward)\n");
		break;
	case DIR_EAST:
		printf(">>> Moving EAST (Right)\n");
		break;
	case DIR_WEST:
		printf(">>> Moving WEST (Left)\n");
		break;
	case DIR_NORTH_EAST:
		printf(">>> Moving NORTH-EAST (Forward-Right)\n");
		break;
	case DIR_NORTH_WEST:
		printf(">>> Moving NORTH-WEST (Forward-Left)\n");
		break;
	case DIR_SOUTH_EAST:
		printf(">>> Moving SOUTH-EAST (Backward-Right)\n");
		break;
	case DIR_SOUTH_WEST:
		printf(">>> Moving SOUTH-WEST (Backward-Left)\n");
		break;
	case DIR_STOP:
		printf(">>> EMERGENCY STOP!\n");
		break;
	}
}

int main()
{
	NavigationState navState;
	SensorData sensors;
	Direction decision;

	navigation_init(&navState);
	srand(time(NULL));

	printf("===========================================\n");
	printf("  USS OBSTACLE AVOIDANCE SYSTEM STARTED\n");
	printf("===========================================\n\n");

	while (1)
	{
		sensors = read_sensors();

		decision = navigation_decide(sensors, &navState);

		printf("\n========================================\n");
		printf("SENSORS: Front:%3d Back:%3d Left:%3d Right:%3d\n",
		       sensors.front, sensors.back, sensors.left, sensors.right);
		printf("DECISION: %s\n", direction_to_string(decision));

		if (is_critical_situation(sensors))
		{
			printf("⚠️  WARNING: Critical obstacle detected!\n");
		}

		execute_movement(decision);

		usleep(100000);
	}

	return 0;
}
