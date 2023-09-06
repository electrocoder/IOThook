import datetime

from rest_framework import status
from rest_framework.exceptions import ValidationError
from rest_framework.response import Response
from rest_framework.views import APIView

from datas.models import Data
from datas.serializers import DataSerializer
from devices.models import Device
from iotv7.group_user_throttle import GroupUserRateThrottle


class DataDeviceApiView(APIView):
    """
    api/device Read Data API.
    :required: API_KEY
    """

    throttle_classes = [GroupUserRateThrottle]

    def get_object(self, api_key):
        """
        Helper method to get the object with given read api_key
        """
        try:
            return Device.objects.get(read_api_key=api_key)
        except Device.DoesNotExist:
            return None

    def get(self, request, *args, **kwargs):
        """
        List all the datas for given requested user
        """
        api_key = request.query_params.get('api_key')
        if not api_key:
            raise ValidationError('API_KEY Missing required parameters')

        device = self.get_object(api_key)

        if request.query_params.get('results'):
            results = int(request.query_params.get('results'))
        else:
            results = 100

        if request.query_params.get('start_date'):
            start_date = request.query_params.get('start_date')
        else:
            start_date = None

        if request.query_params.get('end_date'):
            end_date = request.query_params.get('end_date')
        else:
            end_date = datetime.datetime.now()

        if start_date:
            datas = Data.objects.filter(device=device, pub_date__range=(start_date, end_date))[:results]
        else:
            datas = Data.objects.filter(device=device)[:results]

        serializer = DataSerializer(datas, many=True)
        return Response(serializer.data, status=status.HTTP_200_OK)


class DataUpdateApiView(APIView):
    """
    api/update Write Data API.
    :required: API_KEY
    """

    throttle_classes = [GroupUserRateThrottle]

    def get_object(self, api_key):
        """
        Helper method to get the object with given write api_key
        """
        try:
            return Device.objects.get(write_api_key=api_key)
        except Device.DoesNotExist:
            return None

    def get(self, request, *args, **kwargs):
        """
        GET Method, Write data, for given api_key requested user
        """
        api_key = request.query_params.get('api_key')
        if not api_key:
            raise ValidationError('API_KEY Missing required parameters')

        device = self.get_object(api_key)

        if request.query_params.get('field_1'):
            data = {
                'device': device.pk if device else None,
                'field_1': request.query_params.get('field_1'),
                'field_2': request.query_params.get('field_2'),
                'field_3': request.query_params.get('field_3'),
                'field_4': request.query_params.get('field_4'),
                'field_5': request.query_params.get('field_5'),
                'field_6': request.query_params.get('field_6'),
                'field_7': request.query_params.get('field_7'),
                'field_8': request.query_params.get('field_8'),
            }
            serializer = DataSerializer(data=data)
            if serializer.is_valid():
                serializer.save()
                return Response(serializer.data, status=status.HTTP_201_CREATED)

            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    def post(self, request, *args, **kwargs):
        """
        POST Method, Write data, for given api_key requested user
        """
        api_key = request.data.get('api_key')
        if not api_key:
            raise ValidationError('API_KEY Missing required parameters')

        device = self.get_object(api_key)
        data = {
            'device': device.pk if device else None,
            'field_1': request.data.get('field_1'),
            'field_2': request.data.get('field_2'),
            'field_3': request.data.get('field_3'),
            'field_4': request.data.get('field_4'),
            'field_5': request.data.get('field_5'),
            'field_6': request.data.get('field_6'),
            'field_7': request.data.get('field_7'),
            'field_8': request.data.get('field_8'),
        }
        serializer = DataSerializer(data=data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)

        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
