from django.db import models

from devices.models import Device


class Data(models.Model):
    """
    Device Data manager.
    """
    device = models.ForeignKey(Device, related_name="device_data", on_delete=models.CASCADE)
    field_1 = models.CharField('1. Field Value', max_length=30, help_text='Enter a field value')
    field_2 = models.CharField('2. Field Value', max_length=30, help_text='Enter a field value', null=True, blank=True)
    field_3 = models.CharField('3. Field Value', max_length=30, help_text='Enter a field value', null=True, blank=True)
    field_4 = models.CharField('4. Field Value', max_length=30, help_text='Enter a field value', null=True, blank=True)
    field_5 = models.CharField('5. Field Value', max_length=30, help_text='Enter a field value', null=True, blank=True)
    field_6 = models.CharField('6. Field Value', max_length=30, help_text='Enter a field value', null=True, blank=True)
    field_7 = models.CharField('7. Field Value', max_length=30, help_text='Enter a field value', null=True, blank=True)
    field_8 = models.CharField('8. Field Value', max_length=30, help_text='Enter a field value', null=True, blank=True)
    pub_date = models.DateTimeField('Publish Date', auto_now_add=True)
    enable = models.BooleanField(default=True, help_text='Enable/Disable')

    class Meta:
        ordering = ['-pub_date']

    def __str__(self):
        """
        Return Device Name and Private Key
        """
        return "{}-{}".format(self.device.name, self.pk)
