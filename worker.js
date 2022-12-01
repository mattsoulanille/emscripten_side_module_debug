import {expose, proxy} from 'comlink';
import Module from './dist/main';

const api = {
  run: async () => {
    console.log('Importing emscripten main entrypoint');
    //importScripts('/main.js');
    const main = await Module();
  }
}

expose(api);
