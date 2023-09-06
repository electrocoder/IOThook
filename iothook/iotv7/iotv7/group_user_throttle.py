from rest_framework.throttling import UserRateThrottle, BaseThrottle, ScopedRateThrottle
from rest_framework.throttling import SimpleRateThrottle

from devices.models import Device
from iotv7 import settings
import random

class GroupUserRateThrottle(UserRateThrottle):

    # Set self.scope to the group name you declared in your settings,
    # and also set self.THROTTLE_RATES
    def __init__(self):
        group_rate_settings = settings.REST_FRAMEWORK['GROUP_THROTTLE_RATES']
        self.THROTTLE_RATES = group_rate_settings
        x = list(self.THROTTLE_RATES.keys())[0]
        self.scope = x
        super().__init__()


    # Use a unique key for each user in a group,
    # so one user won't be punished because of others.
    # The final cache_key considers both scope and ident,
    # see throttling.py
    def get_cache_key(self, request, view):
        if 'api/device' in request.build_absolute_uri():
            request.user = Device.objects.get(read_api_key=request.query_params.get('api_key')).user
        elif 'api/update' in request.build_absolute_uri():
            request.user = Device.objects.get(write_api_key=request.data.get('api_key')).user

        if request.user.is_authenticated:
            self.scope = request.user.groups.all()[0].name
        else:
            self.scope = 'Free'
        self.rate = self.THROTTLE_RATES[self.scope]
        ident = request.user.pk

        return self.cache_format % {
            'scope': self.scope,
            'ident': ident
        }
