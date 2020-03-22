src = $(wildcard src/*.cpp) $(wildcard wxEnvelopeGraph/src/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = `wx-config --libs` -lportmidi
CXXFLAGS = `wx-config --cxxflags` -Iinclude -IwxEnvelopeGraph/include -IwxEnvelopeGraph -O2

vzeditor: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXFLAGS)

.PHONY: clean

clean:
	rm -f $(obj) vzeditor
