"""
Archie's BelleBot
She can tell you exactly how many days are left before the end of hacktoberfest-2020
You will need discord.py to run this bot. You can install it via pip using 'pip install discord.py'
"""
from sys import exit
import datetime
from discord.ext import commands
from discord.ext.commands import Bot, when_mentioned_or
from discord import DMChannel, Intents
from aiohttp import ClientSession


class Belle(Bot):
    def __init__(self, *args, **options):
        super().__init__(*args, **options)
        self.session = None

    async def start(self, *args, **kwargs):
        self.session = ClientSession()
        await super().start('The discord token goes here!', *args, **kwargs)

    async def close(self):
        await self.session.close()
        await super().close()


client = Belle(
    command_prefix=when_mentioned_or('Belle, '),
    intents=Intents.default(),
    max_messages=1000
)


@client.event
async def on_ready():
    print('I\'m online!')
    return True


@client.event
async def on_message(msg):
    if isinstance(msg.channel, DMChannel):
        return

    if client.user.mentioned_in(msg):
        end_of_hacktoberfest = datetime.datetime(2020, 10, 31)
        now = datetime.datetime.utcnow()
        discard = datetime.timedelta(minutes=now.minute % 10,
                                     seconds=now.second,
                                     microseconds=now.microsecond)

        now -= discard
        if discard >= datetime.timedelta(minutes=5):
            now += datetime.timedelta(minutes=10)

        delta = end_of_hacktoberfest - now
        await msg.channel.send(f'Hacktoberfest 2020 ends in {delta} hours!')

    await client.process_commands(msg)


@commands.is_owner()
@client.command(
    name='shutdown',
    brief='A little kill switch in case robots take over!',
    hidden=True
)
async def shutdown(ctx):
    await ctx.send('Bye bye!')
    exit(0)


if __name__ == '__main__':
    client.run()
