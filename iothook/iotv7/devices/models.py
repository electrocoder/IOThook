import binascii
import os

from django.contrib.auth.models import User
from django.db import models
from django.db.models import Q
from django.template.defaultfilters import slugify


class Device(models.Model):
    """
    IoT Device manager.
    """
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    read_api_key = models.CharField(max_length=90, blank=True,
                                    help_text=u"API_KEY (Automatically generated), for MQTT secret_username")
    write_api_key = models.CharField(max_length=90, blank=True,
                                     help_text=u"API_KEY (Automatically generated), for MQTT secret_password")
    name = models.CharField(max_length=30, help_text="Device name")
    slug = models.SlugField(max_length=50, help_text=u"Url address (Automatically generated)")
    image = models.ImageField(upload_to='images/%Y/%m/%d', default="images/image.png",
                              help_text='Select Image')
    tags = models.CharField(max_length=50, help_text="Tag(s) write please", blank=True)
    link_external_site = models.URLField(help_text="Web address write please", blank=True)
    field_1 = models.CharField('1. Field Name', max_length=30, help_text='Enter a field name')
    field_2 = models.CharField('2. Field Name', max_length=30, help_text='Enter a field name', null=True, blank=True)
    field_3 = models.CharField('3. Field Name', max_length=30, help_text='Enter a field name', null=True, blank=True)
    field_4 = models.CharField('4. Field Name', max_length=30, help_text='Enter a field name', null=True, blank=True)
    field_5 = models.CharField('5. Field Name', max_length=30, help_text='Enter a field name', null=True, blank=True)
    field_6 = models.CharField('6. Field Name', max_length=30, help_text='Enter a field name', null=True, blank=True)
    field_7 = models.CharField('7. Field Name', max_length=30, help_text='Enter a field name', null=True, blank=True)
    field_8 = models.CharField('8. Field Name', max_length=30, help_text='Enter a field name', null=True, blank=True)
    pub_date = models.DateTimeField('Publish Date', auto_now_add=True)
    enable = models.BooleanField(default=True, help_text='Enable/Disable')

    class Meta:
        ordering = ['-pub_date']

    def __str__(self):
        """
        Return Device Name and Private Key
        """
        return "{}-{}".format(self.name, self.pk)

    def save(self, *args, **kwargs):
        """
        Save Device.
         Slug : Automatically generated
         Read API KEY : Automatically generated
         Write API KEY : Automatically generated
        """
        if not self.slug:
            self.slug = slugify("%s" % self.name)
        if not self.read_api_key:
            self.read_api_key = self.generate_key()
        if not self.write_api_key:
            self.write_api_key = self.generate_key()

        super().save(*args, **kwargs)

    def generate_key(self, salt=12):
        """
        It generates a random string of characters
        :return: A random string of hexadecimal characters.
        """
        unique_token_found = False
        unique_token = ""
        while not unique_token_found:
            unique_token = binascii.hexlify(os.urandom(salt)).decode()
            if Device.objects.filter(Q(read_api_key=unique_token) | Q(write_api_key=unique_token)).count() == 0:
                unique_token_found = True

        return unique_token
