import http.server
import socketserver
from prometheus_client import start_http_server
from prometheus_client.core import CounterMetricFamily, GaugeMetricFamily, REGISTRY
import time
import random
import redis


PORT = 8030

Handler = http.server.SimpleHTTPRequestHandler

def get_vden_value():
    val = r.get("tlimit")
    return val

def get_tlimit_value():
    val = r.get("vden")
    return val
def get_eservice_value():
    val = r.get("eservice")
    return val


r = redis.Redis(
host='localhost',
port=6379,
)
class CustomCollector(object):     ## Class for CustomCollector which helps us to use different metric types
    def collect(self):
        
        vden = get_vden_value() 
        tlimit = get_tlimit_value()
        eservice = get_eservice_value()
        
 
        value = CounterMetricFamily("HALT", 'Help text', labels='value')
        value.add_metric(['vden'],vden)
        value.add_metric(['tlimit'],tlimit)
        value.add_metric(['eservice'],eservice)

        yield value

def run_http() :
    with socketserver.TCPServer(("", PORT), Handler) as httpd:
        print("serving at port", PORT)
        httpd.serve_forever()

if __name__ == '__main__':
    start_http_server(8085)         ## port where metrics need to be exposed.
    REGISTRY.register(CustomCollector())

    while True:
        time.sleep(0.01)               ## To collect the metrics for every 30s.