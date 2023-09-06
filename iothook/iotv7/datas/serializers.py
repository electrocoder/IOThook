from rest_framework import serializers

from datas.models import Data


class DataSerializer(serializers.ModelSerializer):
    """
    Device Data Serializer.
    """

    class Meta:
        model = Data
        fields = ['device', 'pk', 'pub_date', 'field_1', 'field_2', 'field_3', 'field_4', 'field_5', 'field_6',
                  'field_7', 'field_8']

    def to_representation(self, instance):
        """
        Serializer not None or Null
        """
        data = super().to_representation(instance)
        return {k: v for k, v in data.items() if v is not None}
