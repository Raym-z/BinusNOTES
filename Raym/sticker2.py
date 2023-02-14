import discord
from discord.ext import commands
import requests
import json

# Initialize the Discord client
client = commands.Bot(command_prefix="!", intents=discord.Intents.all())

webhook_url = "https://discordapp.com/api/webhooks/1074848036179689523/_6jaWG-7LLakRuw3ywcXVFyGxQzH3vGroFNpc22sP6CiEcKYSkXXHd3ciQl6w-rjAyDw"


with open("StickerBOT\stickers.json") as f:
    stickers = json.load(f)


@client.event
async def on_ready():
    print(f'Logged in as {client.user}!')


@client.event
async def on_message(message):
    # Check if the message is the command to create a new webhook
    if message.author == client.user:
        return

    if message.content.startswith(":") and message.content.endswith(":"):
        sticker = message.content[1:-1].lower()

        if sticker in stickers:
            sticker_url = stickers[sticker]
            channel = message.channel
            username = message.author.nick if message.author.nick else message.author.name
            avatar_url = message.author.guild_avatar or message.author.avatar
            await message.delete()
            # Create a new webhook in the specified channel
            webhook = await channel.create_webhook(name='Codouse')

            # Set the payload for the webhook
            payload = {
                "content": sticker_url,
                "username": username,
                "avatar_url": str(avatar_url)
            }

            # Send the webhook message
            requests.post(webhook.url, data=payload)
            await webhook.delete()
            return


client.run(
    'MTA1NTg3MTgyMjgwMjk4NDk5MA.Ga2vCW.iJWfAe_E7fB0T0tA-YhTFZIF9qc4qdUV8H9vqs')
