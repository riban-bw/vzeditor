src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = `wx-config --libs` -lportmidi
CXXFLAGS = `wx-config --cxxflags` -Iinclude -O2

vzeditor: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXFLAGS)

.PHONY: clean

clean:
	rm -f $(obj) vzeditor
