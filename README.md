# Priority-Airport

## Project Name
Airport Flight Management System

## Purpose
Create an airport flight management system using priority queue.

## Entry
A system will be developed for the management of flights made during the day (during 1-24 hours) at Istanbul Airport, which has 2 runways, 1 landing and 1 departure. While only 1 plane can take off at the airport at the same time, only 1 plane can land. Each of the planes has different priorities in landing and taking off, and a maximum of 24 planes can request permission to land in a day. By using the priority order, landing time, delay time and departure time information of the aircraft at the airport; It is aimed to determine the order of use of the landing runway and the take-off runway.

+ The priority (first_id), aircraft number (plane_id) and requested landing time (request_desired_departure_time) of the aircraft requesting landing at the airport will be read from the input.txt file.
+ For airplanes requesting landing permission from the tower, first of all, it should be checked whether the runway is full or empty at the time of request for landing. If the runway is empty, the desired landing time should be allowed and added to the appropriate place in the landing_runway_usage_order. Otherwise, the landing order of the aircraft should be determined according to priority.
+ “İniş izin talebiniz onaylanmıştır” for each aircraft requesting landing permission or “… nedeniyle iniş izni verilememektedir.” should be printed on the screen.
+ The waiting time for each plane landing at the airport is 1 hour. Delays due to delays should be included in the departure time of the aircraft. The departure time should be calculated with this information in mind.
+ Due to higher priority aircraft, the flight of any aircraft with low priority may be delayed up to 3 times. If there are more than 3 delays, the pending aircraft should be taken off without any priority.
+ Each of the aircraft requesting landing permission should be read from the input.txt line by line. Each line read should be displayed on the screen.
+ When each new input line is read, the output.txt file containing the planes that will take off should be updated and the current takeoff_runway_usage_order priority queue should be displayed on the screen.
+ Projede kullanılacak input.txt dosyası ekte verilmiştir. output.txt dosyası ise proje içerisinde öğrenci tarafından oluşturulacaktır.
+ The input.txt file contains the following information
  + List of planes requesting permission to land at the airport in 1 day
  + 3 information (priority_id, flight_id, requested_initial_time) will be read from the file, respectively (line by line) separated by a space.
+ The output.txt file should be created according to the departure time of the aircraft. The content of the file should be like this
  + Each line should contain a total of 6 information: priority_id, flight_id, requested_land_time, landing_time, delay_time, departure_time.
