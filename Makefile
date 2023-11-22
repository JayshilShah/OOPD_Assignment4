CXX = g++
CXXFLAGS = -std=c++11 -Wall
SOURCES = VehicleDetails.cpp NoticeChallenge.cpp CarReportDetails.cpp AddressToSendNotice.cpp
EXECUTABLES = $(SOURCES:.cpp=)

all: $(EXECUTABLES)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(EXECUTABLES)
